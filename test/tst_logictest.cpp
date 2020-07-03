#include <QtTest>
#include <iostream>

// add necessary includes here
#include "../tictactoe/board.h"

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

private:
    Board *b;

};

logicTest::logicTest()
{

}

logicTest::~logicTest()
{

}

void logicTest::initTestCase()
{
    this->b = new Board(Entry::EMPTY);
}

void logicTest::cleanupTestCase()
{
    delete this->b;
}

void logicTest::test_case1()
{
    std::cout << entryToString(this->b->getStatus()) << std::endl;
}

QTEST_APPLESS_MAIN(logicTest)

#include "tst_logictest.moc"
