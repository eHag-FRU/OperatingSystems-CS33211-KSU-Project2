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




banker: ./src/banker.cpp
	g++ "./src/banker.cpp" -o ./out/banker


run: ./src
	
	make banker
	clear
	./out/banker "./assets/resource_table.txt"

clean:
	rm -f ./out/banker