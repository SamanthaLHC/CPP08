NAME = span

CXX = c++
CXXFLAGS = -MMD -g3 -Wall -Wextra -Werror -std=c++98


INCLUDE = -I./

OBJ_PATH = ./objs/

SRCS = ./main.cpp

OBJS	= $(SRCS:%.cpp=$(OBJ_PATH)%.o)
DEPS	= $(SRCS:%.cpp=$(OBJ_PATH)%.d)

all: $(NAME)

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

$(OBJ_PATH)%.o: $(SRCS_PATH)%.cpp
	mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${OBJ_PATH}

re: fclean
	
	make all

grind: ${NAME}
		valgrind ./$(NAME)

run: $(NAME)
	./$(NAME)

.PHONY: clean fclean re grind test