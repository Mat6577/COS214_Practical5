#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

class CampusComponent {
public:
    virtual ~CampusComponent() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

#endif // CAMPUSCOMPONENT_H
