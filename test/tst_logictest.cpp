#include <QtTest>

// add necessary includes here

class logicTest : public QObject
{
    Q_OBJECT

public:
    logicTest();
    ~logicTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

logicTest::logicTest()
{

}

logicTest::~logicTest()
{

}

void logicTest::initTestCase()
{

}

void logicTest::cleanupTestCase()
{

}

void logicTest::test_case1()
{

}

QTEST_APPLESS_MAIN(logicTest)

#include "tst_logictest.moc"
