.PHONY: clean All

All:
	@echo "----------Building project:[ HangMan - Debug ]----------"
	@cd "HangMan" && "$(MAKE)" -f  "HangMan.mk"
clean:
	@echo "----------Cleaning project:[ HangMan - Debug ]----------"
	@cd "HangMan" && "$(MAKE)" -f  "HangMan.mk" clean
