# ./btc data/input.txt

## You have to create a program which outputs the value of a certain amount of bitcoin on a certain date
This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject -> data/data.csv

 	csv 
	Comma-separated values (CSV) is a plain text data format for storing tabular data where the fields (values) of a record are separated by a comma and each record is a line (i.e. newline separated).

## Your program will use the value in your input file.
	Your program should display on the standard output the result of the value multiplied by the exchange rate according to the date indicated in your database.
	If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one.

## used std::map container
