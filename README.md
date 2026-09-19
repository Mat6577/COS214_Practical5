# COS214_Practical5: CampusGuard

## Team Members
- **Ashley Mthemba** - u25072235
- **Tebello Mohohoma** - u25256387
- **Navela Hlungwani** - [Insert Student Number]

---

## Overview
CampusGuard is an emergency-response coordination platform that manages the lifecycle of campus incidents. It facilitates seamless communication between distinct operational units without tight coupling, manages dynamic incident state transitions, executes operator commands, and provides a simplified workflow for high-level emergency scenarios.

We were instructed to implement 6 of the 23 design patterns. The table of contents lists all the patterns implemented.

---

## Table of Content
| No | Pattern |
|----|---------|
| 1  | [Command](#command) |
| 2  | [Mediator](#mediator) |
| 3  | [Adapter](#adapter) |
| 4  | [Facade](#facade) |
| 5  | [State](#state) |
| 6  | [Template Method](#template-method) |

---

## Command

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| Invoker | `OperatorConsole` |
| Command | `Command` |
| ConcreteCommand | `DispatchUnitCommand`<br>`IssueAlertCommand`<br>`SecureAreaCommand` |
| Receiver | `ResponseComponent` and its subclasses (e.g., `CommunicationService`, `AccessControl`) |

---

## Mediator

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| Mediator | `EmergencyCoordinator` |
| ConcreteMediator | `ConcreteEmergencyCoordinator` |
| Colleague | `ResponseComponent` |
| ConcreteColleague | `CommunicationService`<br>`AccessControl`<br>`CampusSecurity`<br>`MedicalResponders`<br>`FacilityStaff` |

---

## Adapter

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| Target | `AccessControl` |
| Adapter | `AccessControlSystem` |
| Adaptee | `LegacyAccessControlSystem` |

---

## Facade

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| Facade | `HandleEmergency` |
| Subsystems | `OperatorConsole`<br>`ConcreteEmergencyCoordinator`<br>`Stages` |

---

## State

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| Context | `CommunicationService` |
| State | `Stages` |
| ConcreteState | `Detection`<br>`Response`<br>`Recovery` |

---

## Template Method

**Pattern breakdown**
| Participant | Name |
|-------------|------|
| AbstractClass | `CommunicationService` |
| Template Method | `triggerEvent()` |
| PrimitiveOperations | `attendIncident()`<br>`leaveScene()` |
| ConcreteClass | `CampusSecurity`<br>`MedicalResponders`<br>`FacilityStaff` |

---

## Docker Build & Run Instructions

To evaluate the project during the demonstration, the complete application must be built and run inside a Docker container. Ensure you have Docker installed and the daemon running, then execute the following command from the root directory of this repository:

```bash
docker compose up --build
```
This command will build the image natively using the provided `Dockerfile` and `docker-compose.yml`, compile the source files inside the container using the `Makefile`, and execute the `CampusGuard` binary.
