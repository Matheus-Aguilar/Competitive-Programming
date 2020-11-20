EXEFILE      = jacobi-solver
CPUCC     = $(CC)
CPPFLAGS  = -std=c11 -m64 -Ofast -Wall
DEFS      =
INCLUDES  =
LIBDIR    =
LIBS     =  -lm
LINK     =  $(LIBDIR) $(LIBS)

CPU_COMPILE = $(CPUCC) $(DEFS) $(INCLUDES) $(CPPFLAGS)


all: jacobi-solver

	$(CPU_COMPILE)	jacobi-solver.o $(LINK) -o $(EXEFILE) $(PAPILIBS)

jacobi-solver:
	$(CPU_COMPILE) -c jacobi-solver.c


clean:
	rm *.o jacobi-solver
