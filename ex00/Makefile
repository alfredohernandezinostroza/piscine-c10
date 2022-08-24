PROGRAMNAME := ft_display_file
SRCFOLDER := .
OBJSNAMES := main.o
OBJS := $(addprefix $(SRCFOLDER)/,$(OBJSNAMES))

all: $(PROGRAMNAME)

$(PROGRAMNAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(OBJS) -o $(PROGRAMNAME)

$(OBJS): %.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(PROGRAMNAME)

.PHONY = all clean fclean $(PROGRAMNAME)