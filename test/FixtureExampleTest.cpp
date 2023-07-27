#include "gtest/gtest.h"
class C{};

class B{
    C* ptr;
    public:
    B(C* addressOfObject): ptr{addressOfObject}{
        
    }
};

class A{
    B* ptr;
    public:
    A(B* addressOfObject): ptr{addressOfObject}{

    }
    bool operation(){
        return true;
    }
};


class TestFixtureTestsuite:public testing::Test{
    protected:
    A* aPtr;
    B* bPtr;
    C* cPtr;
    TestFixtureTestsuite(){
        // Initialization
    }

    ~TestFixtureTestsuite(){
        // Releasing the resources
    }

void SetUp(){
    // Arrange
    this->cPtr = new C();
    this->bPtr = new B(cPtr);
    this->aPtr = new A(bPtr);
}

void TearDown(){
    // delete resources
    delete cPtr;
    delete bPtr;
    delete aPtr;
}
};


TEST_F(TestFixtureTestsuite, OperationTrueTest){

    // Act and Assert
    ASSERT_TRUE(aPtr->operation());
}

TEST_F(TestFixtureTestsuite, OperationFalseTest){
    // Act and Assert
    ASSERT_FALSE(aPtr->operation());
}