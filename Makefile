CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

SOURCES = \
		main.cpp \
		CampusSecurity.cpp \
		ConcreteEmergencyCoordinator.cpp \
		Detection.cpp \
		DispatchUnitCommand.cpp \
		IssueAlertCommand.cpp \
		LegacyAccessControlSystem.cpp \
		MedicalResponders.cpp \
		OperatorConsole.cpp \
		Recovery.cpp \
		Response.cpp \
		SecureAreaCommand.cpp \
		Stages.cpp \
		FacilityStaff.cpp \
		EmergencyFacade.cpp

TARGET = CampusGuard

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run valgrind clean
