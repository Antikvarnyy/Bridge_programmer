#include <iostream>
using namespace std;

class WorkPlace {
public:
	virtual void place() = 0;
};

class Office : public WorkPlace {
public:
	void place() override {
		cout << "Work from office at ";
	}
};


class Home : public WorkPlace {
public:
	void place() override {
		cout << "Work from home at ";
	}
};


class Working {
protected:
	WorkPlace* workiing;
public:
	Working(WorkPlace* dr) : workiing(dr) {}
	void setWorkPlace(WorkPlace* dr) {
		workiing = dr;
	}
	virtual void work() = 0;
};


class JavaWorking : public Working {
public:
	JavaWorking(WorkPlace* dr) : Working(dr) {}
	void work() override {
		workiing->place();
		cout << "Java" << endl;
	}
};



class CSharpWorking : public Working {
public:
	CSharpWorking(WorkPlace* dr) : Working(dr) {}
	void work() override {
		workiing->place();
		cout << "C#" << endl;
	}
};


int main()
{
	Working* worker = new JavaWorking(new Office());
	worker->work();
	worker->setWorkPlace(new Home());
	worker->work();

	worker = new CSharpWorking(new Office());
	worker->work();
	worker->setWorkPlace(new Home());
	worker->work();

}