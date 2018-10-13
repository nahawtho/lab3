#######################################################################
#
# Copyright (C) 2018 David C. Harrison. All right reserved.
#
# You may not use, distribute, publish, or modify this code without 
# the express written permission of the copyright holder.
#
#######################################################################

################### DO NOT MODIFY THIS FILE ###########################
#
# It is not included in the subission archive ceated by 'make submit'.
#
# If you modify it and your code relies on those modifications, your code
# will not compile in the automated test harness and will be unable to
# execute any tests.
#
# To put it another way, if you modify this file, you will get a big fat
# ZERO on this lab.
#
#######################################################################


CFLAGS = -Wall -Iinclude
CC = g++ -std=c++17

HDRS=$(wildcard include/*.h)
BSRC=$(filter-out src/comply.cc, $(wildcard src/*.cc))
CSRC=$(filter-out src/main.cc, $(wildcard src/*.cc))

bounds: $(BSRC) ${HDRS}
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 2>&1 | tee make.out

check: bounds
	@./check.sh
	@echo ""

grade: clean bounds
	@./grade.sh 

clean:
	@rm -f bounds comply make.out

comply: $(CSRC) ${HDRS}
	$(CC) -o $@ $^ -Iinclude

submit: clean comply
	@tar czvf ~/CMPS109-Lab3.tar.gz \
            --exclude src/comply.cc \
            --exclude include/containable.h \
            src/*.cc include/*.h 
