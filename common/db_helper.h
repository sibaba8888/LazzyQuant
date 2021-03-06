#ifndef DB_HELPER_H
#define DB_HELPER_H

class QSettings;
class QString;

/*!
 * \brief 根据配置连接到数据库.
 * \param pSettings 数据库连接配置.
 * \return 打开数据库是否成功.
 */
bool connectSqlDb(QSettings *pSettings);

/*!
 * \brief 设置默认的db名称并重新打开数据库连接.
 * \param dbName db名称.
 * \return 打开数据库是否成功.
 */
bool setDefaultDbName(const QString &dbName);

/*!
 * \brief 检查数据库连接状态, 如果连接已经失效, 断开重连.
 * \return 数据库连接状态, true正常, false不正常.
 */
bool checkAndReopenDbIfNotAlive();

/*!
 * \brief 检查是否已存在该db, 如果不存在就创建一个.
 * \param dbName db名.
 * \return 如果db已存在或创建成功返回true, 否则返回false.
 */
bool createDbIfNotExists(const QString &dbName);

/*!
 * \brief 检查某db中是否已存在该表, 如果不存在就创建一个.
 * \param dbName db名.
 * \param tblName 表名.
 * \param definition 各表项定义.
 * \return 如果表已存在或创建成功返回true, 否则返回false.
 */
bool createTblIfNotExists(const QString &dbName, const QString &tblName, const QString &definition);

#endif // DB_HELPER_H
