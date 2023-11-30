####################################################
#
#	Producer and consumer problem Make file
#	Using G++ coompiler
#
#	Author: Elliott Hager
#	Date: 10/24/2023
#
#
####################################################

#Menu
msg:
	@echo 'Targets are: '
	@echo ' banker'
	@echo ' run'
	@echo  ' clean'




util: ./src/util.cpp
	g++ -c "./src/util.cpp" -o ./out/util.o

banker: ./src/banker.cpp ./src/util.cpp
	make util
	g++ -c "./src/banker.cpp" -o ./out/banker.o
	g++ "./out/banker.o" "./out/util.o" -o ./out/banker
	
run: ./src
	make banker
	clear
	./out/banker "./assets/resource_table.txt"

clean:
	rm -f ./out/banker
	rm -f ./out/util
	rm -f ./out/*.o