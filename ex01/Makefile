NAME=cpp07_ex01.out
CXXFLAGS= -Werror -Wextra -Wall -std=c++98

SRCS =	main.cpp\
				Span.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re