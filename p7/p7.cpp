#include <iostream>
#include<memory>
using namespace std;

class DatabaseConnection
{
public:
    DatabaseConnection(const string& s) : name(s) {
        cout << "constructorul din DB" << endl;
    }
    void query(const string& q)
    {
        cout << "interogam baza de date" << q << endl;
    }
    ~DatabaseConnection()
    {
        cout << "destructor din DB" << endl;
    }
private:
    string name;
};

class DatabaseUser
{
public:
    DatabaseUser(shared_ptr<DatabaseConnection> conn) : db(conn)
    {
        cout << "constructor din DB connection" << endl;
    }
    void DbQuery(const string& q)
    {
        shared_ptr<DatabaseConnection> shared_p = db.lock();
        if(db.lock() != nullptr)
        {
            db->query(q);
        }
        else
            cout << "conexiune invalida" << endl;

    }

    
private:
    weak_ptr<DatabaseConnection>  db;
};

int main()
{
    shared_ptr< DatabaseConnection> conn = make_shared < DatabaseConnection >("MYSQL");
    DatabaseUser user1(conn);
    DatabaseUser user2(conn);

    user1.DbQuery("SELECT * from users");
    conn.reset();
    user2.DbQuery("SELECT * from users");

    return 0;
    
}

/*
class DatabaseConnection
{
public:
	DatabaseConnection(const string& s) : name(s)
	{
		cout << "Constructorul din DB" << endl;
	}
	void query(const string& q)
	{
		cout << "Interogam baza de date " << q << endl;
	}
	~DatabaseConnection()
	{
		cout << "Destructorul din DB";
	}
private:
	string name;
};
class DatabaseUser
{
public:
	DatabaseUser(shared_ptr<DatabaseConnection> conn) : db(conn)
	{
		cout << "Constructorul din DB connection" << endl;
	}

	void DBQuery(const string& q)
	{
		shared_ptr< DatabaseConnection> shared_p = db.lock();
		if (shared_p != nullptr)
		{
			shared_p->query(q);
		}
		else
			cout << "Conexiunea este invalida" << endl;
	}

	~DatabaseUser()
	{
		cout << "Destructorul din DB user" << endl;
	}
private:
	weak_ptr<DatabaseConnection> db;
};
int main()
{
	shared_ptr< DatabaseConnection> conn = make_shared<DatabaseConnection>("MYSQL");
	DatabaseUser user1(conn);
	DatabaseUser user2(conn);

	user1.DBQuery("SELECT * from users");
	conn.reset();
	user2.DBQuery("SELECT * from users");

	return 0;
}*/