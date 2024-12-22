# Nom de l'exécutable
EXEC = MNH_CWire

# Répertoires des fichiers .c et .h
SRC_DIR = .
INCLUDE_DIR = ./include

# Fichiers sources nécessaires pour la compilation
SRCS = $(SRC_DIR)/arbre.c $(SRC_DIR)/equilibre.c $(SRC_DIR)/traitement.c $(SRC_DIR)/parcours.c $(SRC_DIR)/principal.c

# Fichiers objets (générés automatiquement)
OBJS = $(SRCS:.c=.o)

# Fichiers d'en-tête
HEADERS = $(INCLUDE_DIR)/arbre.h $(INCLUDE_DIR)/equilibre.h $(INCLUDE_DIR)/traitement.h $(INCLUDE_DIR)/parcours.h

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -g -I$(INCLUDE_DIR)  # Options de compilation avec le chemin des fichiers d'en-tête

# Construction de l'exécutable
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Règles de création pour chaque fichier .o (respect de l'ordre et des dépendances)
$(SRC_DIR)/arbre.o: $(SRC_DIR)/arbre.c $(INCLUDE_DIR)/arbre.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/equilibre.o: $(SRC_DIR)/equilibre.c $(INCLUDE_DIR)/equilibre.h $(INCLUDE_DIR)/arbre.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/traitement.o: $(SRC_DIR)/traitement.c $(INCLUDE_DIR)/traitement.h $(INCLUDE_DIR)/arbre.h $(INCLUDE_DIR)/equilibre.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/parcours.o: $(SRC_DIR)/parcours.c $(INCLUDE_DIR)/parcours.h $(INCLUDE_DIR)/arbre.h $(INCLUDE_DIR)/equilibre.h $(INCLUDE_DIR)/traitement.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/principal.o: $(SRC_DIR)/principal.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Règle de nettoyage
clean:
	rm -f $(OBJS) $(EXEC)

# Règle pour tout recompiler
rebuild: clean all
