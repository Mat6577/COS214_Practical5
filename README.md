# COS214_Practical5

## We were instructed to implement 6 of the 23 design patterns. The table of content lists all the patterns implemented.

---

# Table of Content
|No|Pattern|
|-----|----------|
|1|[Command](#Command)|
|2|[Mediator](#Mediator)|
|3|[Adapter](#adapter)|
|4|[Facade](#Facade)|

---

# Command

Pattern breakdown
|Participant|Name|
|-----------|----|
|Invoker|OperatorConsole|
|Command|Command|
|ConcreteCommand|DispatchUnitCommand|
||IssueAlertCommand|
||SecureAreaCommand|
|Receiver|ResponseComponent|
||CommunicationService|
||AccessControlSystem|

---


# Mediator
|Participant|Name|
|-----------|----|
|Colleague|ResponseComponent|
|ConcreteColleague|CommunicationService|
||AccessControlSystem|
|Mediator|EmergencyCoordinator
|ConcreteMediator||

# Adapter
---

---
# Facade