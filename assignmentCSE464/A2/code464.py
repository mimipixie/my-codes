get_ipython().run_line_magic('matplotlib', 'inline')
import pandas as pd
df=pd.read_csv("dataset1_test.csv")
df.columns = ["Batsman","Runs","Mins","BF","f4s","s6s","SR","Pos","Dismissal","Inns"]

#print(df.head(5))
#print(df)


pp1=df[df.Batsman==1]
pp2=df[df.Batsman==2]
pp3=df[df.Batsman==3]
pp4=df[df.Batsman==4]
pp5=df[df.Batsman==5]
pp6=df[df.Batsman==6]


print("Part A  :         \n")

import matplotlib.pyplot as plt
import seaborn as sns
sns.set()

print("          (1) \n")

_ = sns.swarmplot(x = 'Batsman', y = 'SR', data = df)
_ = sns.boxplot(x = 'Batsman', y = 'SR', data = df,boxprops=dict(alpha=.4))
_ = plt.margins(0.02)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('SR')
plt.show()



print("          (2) \n")

sns.set()
_ = sns.swarmplot(x = 'Batsman', y = 'Mins', data = df)
_ = sns.boxplot(x = 'Batsman', y = 'Mins', data = df,boxprops=dict(alpha=.4))
_ = plt.margins(0.02)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('Mins')
plt.show()


print("          (3) \n")


sns.set()
_ = sns.swarmplot(x = 'Batsman', y = 'Runs', data = df)
_ = sns.boxplot(x = 'Batsman', y = 'Runs', data = df,boxprops=dict(alpha=.4))
_ = plt.margins(0.02)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('Runs')
plt.show()

print("          (4) \n")


p1=pp1
p1=p1.sort_values(['BF'], ascending=[True])

p2=pp2
p2=p2.sort_values(['BF'], ascending=[True])

p3=pp3
p3=p3.sort_values(['BF'], ascending=[True])

p4=pp4
p4=p4.sort_values(['BF'], ascending=[True])

p5=pp5
p5=p5.sort_values(['BF'], ascending=[True])

p6=pp6
p6=p6.sort_values(['BF'], ascending=[True])


import matplotlib.pyplot as plt
import seaborn as sns
sns.set()


_ = plt.plot(p1.BF , p1.Runs , marker = 's', linestyle = 'solid', color='blue', label = 'player1')
_ = plt.plot(p2.BF , p2.Runs , marker = 'D', linestyle = 'solid', color='green', label = 'player2')
_ = plt.plot(p3.BF , p3.Runs , marker = 's', linestyle = 'solid', color='red', label = 'player3')
_ = plt.plot(p4.BF , p4.Runs , marker = 'D', linestyle = 'solid', color='purple', label = 'player4')
_ = plt.plot(p5.BF , p5.Runs , marker = 's', linestyle = 'solid', color='yellow', label = 'player5')
_ = plt.plot(p6.BF , p6.Runs , marker = 'D', linestyle = 'solid', color='skyblue', label = 'player6')


_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')
plt.legend()
plt.show()




print("          (5) \n")

p1=pp1
p1=p1.sort_values(['Runs'], ascending=[True])

p2=pp2
p2=p2.sort_values(['Runs'], ascending=[True])

p3=pp3
p3=p3.sort_values(['Runs'], ascending=[True])

p4=pp4
p4=p4.sort_values(['Runs'], ascending=[True])

p5=pp5
p5=p5.sort_values(['Runs'], ascending=[True])

p6=pp6
p6=p6.sort_values(['Runs'], ascending=[True])


import matplotlib.pyplot as plt
import seaborn as sns
sns.set()


_ = plt.plot(p1.Runs , p1.f4s , marker = 's', linestyle = 'solid', color='blue', label = 'player1')
_ = plt.plot(p2.Runs , p2.f4s , marker = 'D', linestyle = 'solid', color='green', label = 'player2')
_ = plt.plot(p3.Runs , p3.f4s , marker = 's', linestyle = 'solid', color='red', label = 'player3')
_ = plt.plot(p4.Runs , p4.f4s , marker = 'D', linestyle = 'solid', color='purple', label = 'player4')
_ = plt.plot(p5.Runs , p5.f4s , marker = 's', linestyle = 'solid', color='yellow', label = 'player5')
_ = plt.plot(p6.Runs , p6.f4s , marker = 'D', linestyle = 'solid', color='skyblue', label = 'player6')



_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.legend()

plt.show()






print("\n\n\n\n       \n")

print("Part C  :         \n")


print("\n   player#1         \n")

import scipy.stats as ss
import math
import statistics

print("normal_distribution:        \n")
pstd1 = statistics.pstdev(pp1['Runs'])
std1=statistics.stdev(pp1['Runs'])
length= len(pp1)
mean1= pp1['Runs'].mean()
z_score= ss.norm.ppf(.95)
print("Z_Score: ", z_score)
part = (pstd1*z_score)/math.sqrt(length)
print("Normal distribution: Confidence interval is between", mean1-part, " to " ,mean1+part)

print("\nt_distribution:        \n")
t_value = ss.t.ppf(.95, length-1)

print("t_Score: ", t_value)
partt = (std1*t_value)/math.sqrt(length) 

print("t distribution: Confidence interval is between", mean1-partt, " to " ,mean1+partt)




print("\n\n   player#2         \n")
print("normal_distribution:        \n")
pstd2 = statistics.pstdev(pp2['Runs'])

std2=statistics.stdev(pp2['Runs'])
length= len(pp2)
mean1= pp2['Runs'].mean()
z_score= ss.norm.ppf(.95)
print("Z_Score: ", z_score)
part = (pstd2*z_score)/math.sqrt(length)
print("Normal distribution: Confidence interval is between", mean1-part, " to " ,mean1+part)

print("\nt_distribution:        \n")
t_value = ss.t.ppf(.95, length-1)

print("t_Score: ", t_value)
partt = (std2*t_value)/math.sqrt(length) 

print("t distribution: Confidence interval is between", mean1-partt, " to " ,mean1+partt)




print("\n\n   player#3         \n")
print("normal_distribution:        \n")
pstd3 = statistics.pstdev(pp3['Runs'])

std3=statistics.stdev(pp3['Runs'])
length= len(pp3)
mean3= pp3['Runs'].mean()
z_score= ss.norm.ppf(.95)
print("Z_Score: ", z_score)
part = (pstd3*z_score)/math.sqrt(length)
print("Normal distribution: Confidence interval is between", mean1-part, " to " ,mean1+part)

print("\nt_distribution:        \n")
t_value = ss.t.ppf(.95, length-1)

print("t_Score: ", t_value)
partt = (std3*t_value)/math.sqrt(length) 

print("t distribution: Confidence interval is between", mean1-partt, " to " ,mean1+partt)





print("\n\n\n\n       \n")

print("Part D  :         \n")


print(pp1['SR'].mean())
print(pp1['Runs'].mean())
print(pp2['SR'].mean())
print(pp2['Runs'].mean())
print(pp3['SR'].mean())
print(pp3['Runs'].mean())
print(pp4['SR'].mean())
print(pp4['Runs'].mean())
print(pp5['SR'].mean())
print(pp5['Runs'].mean())
print(pp6['SR'].mean())
print(pp6['Runs'].mean())


hs1=pp1['Runs'].max()
print("hs1= ", hs1)
hs2=pp2['Runs'].max()
print("hs2= ", hs1)
hs3=pp3['Runs'].max()
print("hs3= ", hs3)
hs4=pp4['Runs'].max()
print("hs4= ", hs4)
hs5=pp5['Runs'].max()
print("hs5= ", hs5)
hs6=pp6['Runs'].max()
print("hs6= ", hs6)





