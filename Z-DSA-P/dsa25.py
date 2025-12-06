'''
Arjun is building a student ranking system for a coding competition.
Each participants name and score are entered into the system.
The program should display the participants sorted by score in descending order, count how many participants scored greater than or equal to a given cutoff, and print the name of the top scorer.

If multiple students have the same highest score, print the one that comes first alphabetically.
If no participants exist, print “No participants”.

input:
5
Arjun 87
Riya 92
Kabir 87
Sneha 99
Amit 92
90

output:
Sneha Riya Amit Arjun Kabir
3
Sneha
'''

n = int(input())
data = []

for i in range(n):
    name, score = input().split()
    score = int(score)
    data.append((name, score))

threshold = int(input())

# ✅ Sort by score (descending), then name (alphabetically)
data.sort(key=lambda x: (-x[1], x[0]))

# 1️⃣ Print names in descending order of score
names = [x[0] for x in data]
print(" ".join(names))

# 2️⃣ Count participants with score >= threshold
count = sum(1 for x in data if x[1] >= threshold)
print(count)

# 3️⃣ Find top scorer
if data:
    top_score = data[0][1]
    # If tie, choose alphabetically first
    top_candidates = [x[0] for x in data if x[1] == top_score]
    print(sorted(top_candidates)[0])
else:
    print("No participants")

    
'''
🧩 Problem Statement

Ravi, a computer science student, is building a program to analyze characters in a given string.
He wants to count how many times each character (including spaces and punctuation) appears in the string.
This will help him study character-level frequency in messages.

The program should:

Read a string input.

Calculate the frequency of each character (case-sensitive).

Store the result in a dictionary.

Finally, display the dictionary in a user-friendly format.

input:
Hello!

output:
H 1
e 1
l 2
o 1
! 1
'''



word = "hello world !"

freq = {}

for i in word:
    freq[i] = freq.get(i,0) + 1

for keys,values in freq.items():
    print(f"{keys} : {values}")




'''
Problem Statement
You are given the daily weights of a person over multiple consecutive days. Write a program to analyze these weights as follows:

Calculate the day-to-day weight changes (difference between each day and the previous day) from the second day onward. Store these changes in a dictionary, where the key is the day's name (e.g., 'Day2'), and the value is the difference compared to the previous day.

Compute the average daily change (average of all the day-to-day changes), rounded to two decimal places.

Predict the weight for the next day by adding the average daily change to the last recorded weight. Output the predicted value rounded to two decimal places.

Input Format
The first line contains an integer N, the number of days.

The next N pairs of lines contain:

Day name (e.g., Day1, Day2, etc.)

Weight on that day (float value)

Output Format
First line: Print the dictionary of daily changes from the second day onward (key: day name, value: change).

Second line: Print the average daily change (rounded to 2 decimal places).

Third line: Print the predicted weight for the next day (rounded to 2 decimal places).

Sample Input 1
text
4
Day1
75.0
Day2
74.0
Day3
73.5
Day4
74.0


Sample Output 1
text
{'Day2': -1.0, 'Day3': -0.5, 'Day4': 0.5}
-0.33
73.67
'''

n = int(input())
days = []
weights = []

for _ in range(n):
    day_name = input().strip()
    weight = float(input().strip())
    days.append(day_name)
    weights.append(weight)

# Calculate day-to-day changes
changes = {}
for i in range(1, n):
    change = weights[i] - weights[i - 1]
    changes[days[i]] = change

# Compute average daily change
average_change = round(sum(changes.values()) / len(changes), 2)

# Predict the next day's weight
predicted_weight = round(weights[-1] + average_change, 2)

print(changes)
print(average_change)
print(predicted_weight)
