#include "cleaner_date.h"
#include "cleaner_date_p.h"

#include <QStringList>
#include <QVariant>
#include <QDate>

#include <Qpe/Core/CronTimer>
#include "../utils/apppathconversion.h"

namespace Qpe
{

static const QLatin1String PROP_PATH				("path");
static const QLatin1String PROP_ENABLED				("enabled");
static const QLatin1String PROP_FILTERS				("filters");
static const QLatin1String PROP_KEEP_INTERVAL		("keepInterval");
static const QLatin1String PROP_FILE_NAME_PATTERN	("fileNamePattern");
static const QLatin1String PROP_CRON				("cron");


static const QLatin1String REG_EX_EMPTY				("^.+$");
static const QLatin1String REG_EX_SPLITER			("\\s*(,|\\||\\+)\\s*");
static const QLatin1String REG_EX_KEEP_INTERVAL		("^\\s*"
													 "(?<value>\\d+)\\s*"
													 "(?<type>(?:%1))s?"
													 "\\s*$");
static const QLatin1String REG_CAP_TYPE		("type");
static const QLatin1String REG_CAP_VALUE	("value");
static const QLatin1String REG_CAP_YEAR		("year");
static const QLatin1String REG_CAP_MONTH	("month");
static const QLatin1String REG_CAP_DAY		("day");

DateLoggerCleanerPrivate::DateLoggerCleanerPrivate()
{
}

DateLoggerCleanerPrivate::~DateLoggerCleanerPrivate()
{
}

bool DateLoggerCleanerPrivate::isEnabled(const QVariant& value) const
{
	return value.isValid() ? value.toBool() : true;
}

bool DateLoggerCleanerPrivate::initializePath(const QVariantMap& p)
{
	LoggerPrivate::AppPathConversionPattern pattern;
	typedef LoggerPrivate::AppPathConversionFactory Factory;
	pattern.initialize(
		p.value(PROP_PATH).toString(),
		Factory::expressionNames(), &Factory::createExpression);
	path.setPath(pattern.createString(p));
	return true;
}

bool DateLoggerCleanerPrivate::initializeFilters(const QVariant& value)
{
	QStringList filterList;
	if (value.type() == QVariant::StringList) {
		filterList = value.toStringList().filter(QRegularExpression(REG_EX_EMPTY));
	} else {
		QRegularExpression spliter(REG_EX_SPLITER);
		filterList = value.toString().split(spliter, QString::SkipEmptyParts);
	}
	if (filterList.isEmpty()) {
		path.setFilter(
			QDir::Files | QDir::Dirs | QDir::AllDirs | QDir::NoDotAndDotDot);
	} else {
		Filter filters;
		for (const QString& filterItem : filterList) {
			filters |= Filter(filterItem, Qt::CaseInsensitive);
		}
		QDir::Filters f(static_cast<QDir::Filter>(filters.value()));
		if (filters.test(QDir::Dirs)) {
			f |= QDir::AllDirs | QDir::NoDotAndDotDot;
		}
		path.setFilter(f);
	}
	return true;
}

bool DateLoggerCleanerPrivate::initializeKeepInterval(const QString& interval)
{
	QRegularExpression r(
		QString(REG_EX_KEEP_INTERVAL)
			.arg(QStringList(KeepInterval::keys().toList()).join('|')),
		QRegularExpression::CaseInsensitiveOption);

	KeepInterval t;
	QRegularExpressionMatch m = r.match(interval);
	if (m.hasMatch()) {
		t = KeepInterval(m.captured(REG_CAP_TYPE), Qt::CaseInsensitive);
		keepIntervalValue = m.captured(REG_CAP_VALUE).toInt();
	}
	keepInterval = t;
	return keepInterval.isValid();
}

bool DateLoggerCleanerPrivate::initializeFileNamePattern(const QString& pattern)
{
	fileNamePattern = QRegularExpression(pattern);
	return fileNamePattern.isValid();
}

bool DateLoggerCleanerPrivate::start(const QString& cron)
{
	QSharedPointer<CronTimer> t(new CronTimer(), &QObject::deleteLater);
	QObject::connect(t.data(), &CronTimer::wakeUp, [this] () { clean(); });
	t->start(cron);
	bool result = t->isActive();
	if (result) { cronTimer = t; }
	return result;
}

void DateLoggerCleanerPrivate::clean()
{
	QStringList result;
	path.refresh();
	QStringList items = path.entryList();
	std::for_each(items.constBegin(), items.constEnd(),
	[this, &result] (const QString& item)
	{
		QRegularExpressionMatch m = fileNamePattern.match(item);
		QDate d;
		if (m.hasMatch() &&
			(d = QDate(
				m.captured(REG_CAP_YEAR).toInt(),
				m.captured(REG_CAP_MONTH).toInt(),
				m.captured(REG_CAP_DAY).toInt())).isValid() &&
			shouldClean(d))
		{
			QDir d = path.filePath(item);
			d.removeRecursively();
		}
	});
}

bool DateLoggerCleanerPrivate::shouldClean(const QDate& date) const
{
	QDate beginInterval;
	QDate endInterval = QDate::currentDate();
	switch (keepInterval.value()) {
	case KeepIntervalType::Day:
		beginInterval = endInterval.addDays(-keepIntervalValue);
		break;
	case KeepIntervalType::Week:
		beginInterval = endInterval.addDays(-(keepIntervalValue * 7));
		break;
	case KeepIntervalType::Month:
		beginInterval = endInterval.addMonths(-keepIntervalValue);
		break;
	case KeepIntervalType::Year:
		beginInterval = endInterval.addYears(-keepIntervalValue);
		break;
	}
	return date <= beginInterval;
}

// ---------------------------------------------------------------------------

DateLoggerCleaner::DateLoggerCleaner(DateLoggerCleanerPrivate* dd)
	: d_ptr(dd)
{
	Q_D(DateLoggerCleaner);
	d->q_ptr = this;
}

DateLoggerCleaner::DateLoggerCleaner()
	: d_ptr(new DateLoggerCleanerPrivate())
{
	Q_D(DateLoggerCleaner);
	d->q_ptr = this;
}

DateLoggerCleaner::~DateLoggerCleaner()
{
}

bool DateLoggerCleaner::initialize(const QVariantMap& properties)
{
	Q_D(DateLoggerCleaner);
	return
		d->isEnabled(properties.value(PROP_ENABLED)) &&
		d->initializePath(properties) &&
		d->initializeFilters(properties.value(PROP_FILTERS)) &&
		d->initializeKeepInterval(properties.value(PROP_KEEP_INTERVAL).toString()) &&
		d->initializeFileNamePattern(properties.value(PROP_FILE_NAME_PATTERN).toString()) &&
		d->start(properties.value(PROP_CRON).toString());
}

} // namespace Qpe
