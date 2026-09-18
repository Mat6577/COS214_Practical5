#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

/**
 * @class CampusComponent
 * @brief Utility class
 * 
 * @details It is used as an instance variable for the SecureAre command. It can be locked and unlocked
 * @date 18/09/2026
 */
class CampusComponent {
public:
    virtual ~CampusComponent() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

#endif // CAMPUSCOMPONENT_H
