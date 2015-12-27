#include<iostream>
#include <cstring>
using namespace std;
class Component
{
  public:
    Component(std::string name, double salary)
          : m_fullName(name), m_valueSalary (salary) {}

    virtual void printSalary(int level) = 0;
    std::string            m_fullName;
    double                 m_valueSalary;
};

/** "Leaf" */
class Worker : public Component
{
  public:
    Worker(std::string name , double salary): Component(name,salary)
    {
    }
    void printSalary(int level)
    {
        for(int j=0; j < level; ++j) cout << "\t";
        cout << "Worker : " <<
            m_fullName.c_str() << ",salary: " <<
            m_valueSalary << "$\n";
    }
};

/** "Composite" */
class Manager: public Component
{
  public:
    Manager(std::string name , double salary) : Component(name,salary)
    {
    }
    void add(Component *cmp)
    {
        m_children.push_back(cmp);
    }
    void printSalary(int level)
    {
        for(int j=0; j < level; ++j) cout << "\t";
        cout << "Manager : " <<  this->m_fullName.c_str() <<
            ",salary: " << m_valueSalary << "$\n";

        if(!m_children.empty())
        {
            for(int x=0; x < level; ++x) cout << "\t";
            cout << "Subordinates  of " <<
                m_fullName.c_str() << ":\n";
            ++level;
            for (int i = 0; i < m_children.size(); ++i)
              m_children[i]->printSalary(level);
        }
    }

   private:
    vector < Component * > m_children;
};

int main()
{
    Manager president ("X", 1000000.0);

    Manager manager_production_department ("Y",400000.0);
    Manager manager_engineering_department ("Z",400000.0);
    Manager manager_quality_control_department ("A",280000.0);
    Manager manager_sales_management_division ("B",270000.0);
    Manager manager_general_affairs_department ("C" ,200000.0);

    Manager team_leader_RandD ("D", 250000.0);
    Manager team_leader_QA ("E", 200000.0);

    Worker software_developer1 ("F", 200000.0);
    Worker software_developer2 ("G", 240000.0);
    Worker tester ("H", 130000.0);

    president.add(&manager_production_department);
    president.add(&manager_engineering_department);
    president.add(&manager_quality_control_department);
    president.add(&manager_sales_management_division);
    president.add(&manager_general_affairs_department );

    manager_engineering_department.add(&team_leader_RandD);
    manager_engineering_department.add(&team_leader_QA );

    team_leader_RandD.add(&software_developer1);
    team_leader_RandD.add(&software_developer2);

    team_leader_QA.add(&tester);

    cout << "The hierarchy of the company,\ni.e. president and all who is under his supervision :\n\n" ;
    president.printSalary(0);

    cout << '\n';
}
