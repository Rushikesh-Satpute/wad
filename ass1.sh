#!/bin/bash
create()
{
	echo "Enter file name."
	read filename
	if [ -f $filename ]
	then
		echo "File exists"
	else
	touch $filename
	fi
	echo "Address book is created."
}

insert()
{
	echo "Enter number of records you want to insert: "
	read n
	echo "Insert data like: "
	echo "ROLL NO    NAME	   MOBILE        EMAIL        CITY"
	for (( i=0;i<n;i++ ))
	do
		read a 
		echo $a>>$filename
	done
	echo "Data is inserted"
}

display()
{
	echo "Student address book is as follows: "
	echo "ROLL NO 	NAME  MOBILE      EMAIL       CITY"
	cat $filename
}
search()
{
	echo "Enter roll number for search: "
	read s
	
	if [ $(grep -wc "$s" $filename) -eq 1 ]
	then
		echo "Record found"
		echo "ROLL NO 	NAME  MOBILE      EMAIL       CITY"
		grep -w "$s" $filename
	else
	echo "Record not found"
	fi
}
delete()
{
	echo "Enter the roll number to be deleted"
	read s 
	grep -v "$s" $filename > filename2 ; mv filename2 $filename
	echo "Record deleted"
}
modify()
{
	echo "Enter roll number to be modified: "
	read s
	echo "Enter new record: "
	echo "ROLL NO 	NAME  MOBILE      EMAIL       CITY"
	read r
	sed -i "/$s/c $r" $filename
	echo "record is modified"
}
#switch-case
until [ "$ch" = "7" ]; do

echo "*ADDRESS BOOK**"
echo "1.Create"
echo "2.Insert"
echo "3.Display"
echo "4.Search"
echo "5.Delete"
echo "6.Modify"
echo "7.Exit"
echo "Enter your choice: "
read ch
case $ch in
	1) create;;
	
	2) insert;;
	
	3) display;;
	
	4) search;;
	
	5) delete;;
	
	6) modify;;
	
	7) ;;
esac
done
