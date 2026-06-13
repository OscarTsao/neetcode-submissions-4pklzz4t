class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    // Implement Adult filter
    bool apply(Person& person) {
        return person.getAge() >= 18;
    }
};

class SeniorFilter : public PersonFilter {
    // Implement Senior filter
    bool apply(Person& person) {
        return person.getAge() >= 65;
    }
};

class MarriedFilter : public PersonFilter {
    // Implement Married filter
    bool apply(Person& person) {
        return person.isMarried();
    }
};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        // Implement method here
        int sum = 0;
        for (Person& p : people) {
            if (filter->apply(p)) {
                sum++;
            }
        }
        return sum;
    }
};
