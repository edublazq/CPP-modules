SUBDIRS = ex00 ex01 ex02 ex03

all clean fclean re:
	@for dir in $(SUBDIRS); do \
		echo "==> $@ en $$dir"; \
		$(MAKE) -C $$dir $@ || exit 1; \
	done

.PHONY: all clean fclean re