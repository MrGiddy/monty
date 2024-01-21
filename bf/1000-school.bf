[
Print "School" in Brainfu*ck

# Char  'S' 'c' 'h'   'o' 'o' 'l'
# Ascii 83  99   104  111 111 108
]

#S: 83
+++++++++		# c0: 9
[			# Enter loop if c0 != 0
	>+++++++++	# Move pointer to c1 and add 9 to it
	<-		# Move pointer to c0 and decrement its value by 1
]			# If c0 is 0 end loop else enter loop

			# At loop exit c0: 0 and c1: 81

>++			# Move pointer to c1 and add 2 to it
.			# Print c1

#c: 99
>+++++++++++
[
	>+++++++++<-
]
>
.

#h: 104
>++++++++++
[
	>++++++++++<-
]
>++++
.

#o: 111
>+++++++++++
[
	>++++++++++<-
]
>+
.

#o: 111
.

#l: 108
# Subtracting 3 from 111
---
.

>++++++++++.		# Print a new line character
