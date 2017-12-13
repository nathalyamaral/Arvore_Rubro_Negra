SRC = main.cpp \
      texto.cpp \
      indice.cpp \
      item_indice.cpp \
      arvrn.cpp \
      no.cpp 

arvrn: $(SRC)
	g++ -o $@ $(SRC) -std=c++11 -Wall -static-libstdc++

clean:
	rm -f arvrn
