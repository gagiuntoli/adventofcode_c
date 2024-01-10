all: main

STDGI:=../../stdg
STDGL:=../../stdg/stdg.so
FLAGS=-g

main: *.c 
	gcc $(FLAGS) $^ $(STDGL) -I $(STDGI) -o $@

