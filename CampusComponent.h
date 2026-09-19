#ifndef CAMPUSCOMPONENT_H
#define CAMPUSCOMPONENT_H

/**
 * @class CampusComponent
 * @brief Utility class
 * 
 * @details It is used as an instance variable for the SecureArea command. It can be locked and unlocked
 * @date 18/09/2026
 */
class CampusComponent {
public:
    virtual ~CampusComponent() = default;
    virtual void lock() {
        std::cout << "This area is locked from access, please try again later.\n";
    }
    virtual void unlock() {
        std::cout << "This area has been unlocked. The public can now access the premises.\n";
    }
};

#endif // CAMPUSCOMPONENT_H
