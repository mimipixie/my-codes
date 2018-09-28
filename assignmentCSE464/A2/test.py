
# coding: utf-8

# In[1]:


get_ipython().run_line_magic('matplotlib', 'inline')
import pandas as pd
df=pd.read_csv("dataset1_test.csv")
df.columns = ["Batsman","Runs","Mins","BF","4s","6s","SR","Pos","Dismissal","Inns"]
print(df.head(5))


# In[153]:


import matplotlib.pyplot as plt
import seaborn as sns
sns.set()
_ = sns.swarmplot(x= 'Batsman', y = 'SR',data=df)
_ = sns.boxplot(x = 'Batsman', y = 'SR', data =df, boxprops=dict(alpha=.4))
_ = plt.margins(0.04)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('SR')
plt.show()


# In[154]:


import seaborn as sns
sns.set()
_ = sns.swarmplot(x = 'Batsman', y = 'Mins', data = df)
_ = sns.boxplot(x = 'Batsman', y = 'Mins', data =df, boxprops=dict(alpha=.4))
_ = plt.margins(0.04)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('Mins')
plt.show()


# In[152]:


import seaborn as sns
sns.set()
_ = sns.swarmplot(x = 'Batsman', y = 'Runs', data = df)
_ = sns.boxplot(x = 'Batsman', y = 'Runs', data = df, boxprops=dict(alpha=.4) )
_ = plt.margins(0.04)
_ = plt.xlabel ('Batsman')
_ = plt.ylabel ('Runs')
plt.show()


# In[6]:


pl1 = df[(df.Batsman == 1)]
pl1.shape


# In[8]:


pl2 = df[(df.Batsman == 2)]
pl2.shape


# In[9]:


pl3 = df[(df.Batsman == 3)]
pl3.shape


# In[10]:


pl4 = df[(df.Batsman == 4)]
pl4.shape


# In[11]:


pl5 = df[(df.Batsman == 5)]
pl5.shape


# In[12]:


pl6 = df[(df.Batsman == 6)]
pl6.shape


# In[13]:


df.shape


# In[157]:



p1=pl1
p1=p1.sort_values(by=['BF'])
p2=pl2
p2=p2.sort_values(by=['BF'])
p3=pl3
p3=p3.sort_values(by=['BF'])
p4=pl4
p4=p4.sort_values(by=['BF'])
p5=pl5
p5=p5.sort_values(by=['BF'])
p6=pl6
p6=p6.sort_values(by=['BF'])
x = p1['BF']
y = p1['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='blue')


x = p2['BF']
y = p2['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='green')


x = p3['BF']
y = p3['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='red')


x = p4['BF']
y = p4['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='purple')


x = p5['BF']
y = p5['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='yellow')


x = p6['BF']
y = p6['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='skyblue')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')

plt.show()


# In[158]:



p1=pl1
p1=p1.sort_values(by=['BF'])
x = p1['BF']
y = p1['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='blue')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')
plt.show()


# In[162]:



x = p2['BF']
y = p2['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='green')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')

plt.show()


# In[159]:


x = p3['BF']
y = p3['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-',color='red')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')
plt.show()


# In[165]:


x = p4['BF']
y = p4['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='purple')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')

plt.show()


# In[164]:


x = p5['BF']
y = p5['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-',color='yellow')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')

plt.show()


# In[163]:


x = p6['BF']
y = p6['Runs']
_ = plt.plot(x, y, marker = 'D', linestyle = '-', color='skyblue')
_ = plt.xlabel ('BF')
_ = plt.ylabel ('Runs')
plt.show()


# In[179]:



x = p1['Runs']
y = p1['4s']
_ = plt.plot(x, y, marker = 's', linestyle = '',color='Blue')  

x = p2['Runs']
y = p2['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='green')

x = p3['Runs']
y = p3['4s']
_ = plt.plot(x, y, marker = 's', linestyle = '',color='Red')

x = p4['Runs']
y = p4['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='purple')


x = p5['Runs']
y = pl5['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='yellow')


x = p6['Runs']
_ = plt.plot(x, p6['4s'], marker = 's', linestyle = '', color='skyblue')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')

#p1=:s p2= -D p3= --s p4= -.D p5= --D p6= -s

plt.show()


# In[178]:


x = p1['Runs']
y = p1['4s']
_ = plt.plot(x, y, marker = 's', linestyle = '',color='Blue')  
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[177]:


x = p2['Runs']
y = p2['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='green')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[176]:


x = p3['Runs']
y = p3['4s']
_ = plt.plot(x, y, marker = 's', linestyle = '',color='Red')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[175]:


x = p4['Runs']
y = p4['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='purple')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[174]:


x = p5['Runs']
y = pl5['4s']
_ = plt.plot(x, y, marker = 'D', linestyle = '',color='yellow')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[173]:


x = p6['Runs']
_ = plt.plot(x, p6['4s'], marker = 's', linestyle = '', color='skyblue')
_ = plt.xlabel ('Runs')
_ = plt.ylabel ('4s')
plt.show()


# In[117]:


pl1['SR'].mean()


# In[118]:


pl1['Runs'].mean()


# In[119]:


pl2['SR'].mean()


# In[120]:


pl2['Runs'].mean()


# In[121]:


pl3['SR'].mean()


# In[127]:


pl3['Runs'].mean()


# In[128]:


pl4['SR'].mean()


# In[130]:


pl4['Runs'].mean()


# In[131]:


pl5['SR'].mean()


# In[132]:


pl5['Runs'].mean()


# In[133]:


pl6['SR'].mean()


# In[134]:


pl6['Runs'].mean()


# In[136]:


hs1=pl1['Runs'].max()
print("hs1= ", hs1)
hs2=pl2['Runs'].max()
print("hs2= ", hs1)
hs3=pl3['Runs'].max()
print("hs3= ", hs3)
hs4=pl4['Runs'].max()
print("hs4= ", hs4)
hs5=pl5['Runs'].max()
print("hs5= ", hs5)
hs6=pl6['Runs'].max()
print("hs6= ", hs6)

