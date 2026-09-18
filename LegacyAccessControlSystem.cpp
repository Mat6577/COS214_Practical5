#include "LegacyAccessControlSystem.h"

/**
 * @brief This is the legacy method
 * @param a CampusComponent instance pointer
 * @param b Password which is required by the legacy system
 * 
 * @throws An invalid argument exception for anincorrect password.
 * @details The target passes in parameters which are required by the legacy code to be able to function
 * @date 18/09/2026
 */
void LegacyAccessControlSystem::lockArea(CampusComponent *area, std::string password)
{
    if (password == "1234") {
        area->lock();        
    } else {
        throw std::invalid_argument("The password is invalid. Provided: " + password);
    }
}

/// @brief Same intent as the lock method, but this is used to unlock the passed in area 
void LegacyAccessControlSystem::unlockArea(CampusComponent *area, std::string password)
{
    if (password == "4321") {
        area->unlock();        
    } else {
        throw std::invalid_argument("The password is invalid. Provided: " + password);
    }
}
