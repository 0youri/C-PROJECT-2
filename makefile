GPP = g++
GPP_O = -std=c++11 -Wall -c

all: bin/test

bin/test: obj/mainTest.o obj/Profil.o obj/EnsembleProfils.o obj/Avis.o
	${GPP} $^ -o $@

obj/mainTest.o: src/core/mainTest.cpp src/core/EnsembleProfils.h
	${GPP} -std=c++11 ${GPP_O} $< -o $@

obj/Profil.o: src/core/Profil.cpp src/core/Profil.h src/core/Avis.h
	${GPP} ${GPP_O} $< -o $@

obj/EnsembleProfils.o: src/core/EnsembleProfils.cpp src/core/EnsembleProfils.h src/core/Profil.h
	${GPP} ${GPP_O} $< -o $@

obj/Avis.o: src/core/Avis.cpp src/core/Avis.h
	${GPP} ${GPP_O} $< -o $@

clean:
	rm obj/*.o bin/*