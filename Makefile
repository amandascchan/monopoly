CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = bb7k
OBJECTS = ./Board/board.o ./Card/nhcard.o ./Card/slccard.o ./data/npdata.o ./data/playerdata.o ./data/squaredata.o ./DeckBuilder/deckbuilder.o ./main.o ./Player/player.o ./Square/NonProperty/collectOSAP.o ./Square/NonProperty/coopFee.o ./Square/NonProperty/gooseNest.o ./Square/NonProperty/goToTimsLine.o ./Square/NonProperty/needlesHall.o ./Square/NonProperty/nonproperty.o ./Square/NonProperty/SLC.o ./Square/NonProperty/timsLine.o ./Square/NonProperty/tuition.o ./Square/Property/Academic/academic.o ./Square/Property/Gym/gym.o ./Square/Property/property.o ./Square/Property/Residence/residence.o ./Square/square.o ./TextDisplay/textdisplay.o ./TCUP/tcup.o ./Card/CommunityChest/advanceToGo.o ./Card/CommunityChest/getOutOfJail.o ./Card/CommunityChest/goToJail.o ./Card/CommunityChest/streetRepairs.o ./Card/CommunityChest/grandOperaNight.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
