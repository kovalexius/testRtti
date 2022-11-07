#include <iostream>
#include <typeinfo>

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QObject>

class RttiBase
{
public:
	virtual void Method()
	{
		std::cout << "Base Method" << std::endl;
	}

	virtual ~RttiBase()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
};

class RttiDerived : public RttiBase
{
public:
	void Method() override
	{
		std::cout << "Derived Method" << std::endl;
	}
};

void TestRttiBase(RttiBase* _base)
{
	if (_base)
	{
		std::cout << __FUNCTION__ << " Type of _base: \"" << typeid(*_base).name() << "\"" << std::endl;
		_base->Method();
	}
}

void TestRttiQt(QObject* _object)
{
	if(_object)
		std::cout << __FUNCTION__ << " Type of _object: \"" << typeid(*_object).name() << "\"" << std::endl;
}

int main(int argc, char** argv)
{
	RttiBase* base1 = new RttiDerived;
	TestRttiBase(base1);
	//std::cout << " Type of base1: \"" << typeid(base1).name() << "\"" << std::endl;

	RttiBase& base2 = RttiDerived();
	std::cout << " Type of base2: \"" << typeid(base2).name() << "\"" << std::endl;
	
	QApplication app(argc, argv);
	QWidget* widget1 = new QPushButton("button1", nullptr);
	TestRttiQt(widget1);
	//std::cout << " Type of widget1: \"" << typeid(widget1).name() << "\"" << std::endl;

	QWidget& widget2 = QPushButton("button2", nullptr);
	std::cout << " Type of widget2: \"" << typeid(widget2).name() << "\"" << std::endl;
	
	return 0;
}