name := start

src = Fwoosh.cpp ATarget.cpp ASpell.cpp main.cpp Warlock.cpp\
	Dummy.cpp Polymorph.cpp Fireball.cpp BrickWall.cpp SpellBook.cpp\
	TargetGenerator.cpp

obj = $(patsubst %.cpp, %.o, $(src))

 %.o: %.cpp
	$(cc)  -c $< -o $@

cc = clang++ -g -std=c++98 -Wall -Wextra -Werror

all:	$(name)

$(name): 	$(obj) *.hpp
	$(cc) $(obj) -o $(name)

clean:
	rm $(obj)

check_space:
	df -h  #check space on the disc