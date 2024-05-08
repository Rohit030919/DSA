def initializeHashing():
	size = int(input("Enter size of hash table"))
	hashTable = [[-1,"null"] for i in range(size)]
	print("Size of hashtable: " ,size)
	return size, hashTable

choice = 1
while(choice!=3):
	print("1. Linear Probing")
	print("2. Double Hashing")
	print("3. HashTable")
	print("3. Exit")
	count = 0
	choice = int(input("Enter choice"))
	if(choice==1):
		size,hashTable = initializeHashing()
		while(choice!=3):
			print("1. Insertion")
			print("2. Searching")
			print("3. Main Menu")
			choice= int(input("Enter choice "))
			if(choice==1):
				name = input("Enter your name ")
				number = int(input("Enter number "))
				hashValue = number%size
				while(hashTable[hashValue][0]!=-1):
					print("Collision Required")
					hashValue = (number+1)%size
				hashTable[hashValue][0] = number
				hashTable[hashValue][1] = name
			if(choice==2):
				comparison = 0
				number = int(input("Enter number to search "))
				hashValue = number%size
				while(hashTable[hashValue][0]!=number and comparison<size):
					hashValue = (number+1)%size
					comparison+=1
				if(comparison<size):
					print("We found the number " , hashTable[hashValue])
			
	if(choice==2):
		size,hashTable = initializeHashing()
		while(choice!=3):
			print("1. Insertion")
			print("2. Searching")
			print("3. Main Menu")
			choice= int(input("Enter choice "))
			if(choice==1):
				
				name = input("Enter your name ")
				number = int(input("Enter number "))
				h1 = number%size
				hashValue = number%size
				i = 1
				while(hashTable[hashValue][0]!=-1):
					print("Collision Required")
					h2 = 7 - (number%7)
					hashValue = (h1+(i*h2))%size
					i+=1
				hashTable[hashValue][0] = number
				hashTable[hashValue][1] = name
			if(choice==2):
				comparison = 0
				number = int(input("Enter number to search "))
				h1 = number%size
				hashValue = (number)%size
				i = 0
				while(hashTable[hashValue][0]!=number and comparison<size):
					h2 = 7 - (number%7)
					hashValue = (h1+(i*h2))%size
					comparison+=1
					i+=1
				if(comparison<size):
					print("We found the number " , hashTable[hashValue])
				else:
					print("Not Found")
	if(choice == 3):
		print(hashTable)
		
		
