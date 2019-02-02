#autoimmune.py
#student id: 15315901
#name: Taidgh Murray


#Import files
from sklearn import model_selection
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
import pandas as pan
from pandas.plotting import scatter_matrix
import matplotlib.pyplot as plt
import imp
import os

#import data set
file = "C:\\Users\\Taidgh\\Documents\\School Work\\4th Year\\CT475\\Assignment 1\\autoimmune.csv"
labels = ["Age","Blood_Pressure","BMI","Plasma_Level","Autoimmune_Disease","Adverse_Events","Drug_in_Serum","Liver_Fuction","Activity_Test","Secondary_Test"]
data = pan.read_csv(file, names=labels)

print('\n')

print(data.shape)

print('\n')

array = data.values
X = array[:,0:4]
Y = array[:,4]
validation_size = .2
seed = 13
scoring = 'accuracy'

X_train, X_validation, Y_train, Y_validation = model_selection.train_test_split(X,Y,test_size=validation_size, random_state=seed)


models = []
models.append(('KNN',KNeighborsClassifier()))
models.append(('NB',GaussianNB()))

results = []
names = []

for name, model in models:
    kfold = model_selection.KFold(n_splits=10, random_state=seed)
    cv_results = model_selection.cross_val_score(model, X_train, Y_train, cv=kfold, scoring=scoring)
    results.append(cv_results)
    names.append(name)
    print("{}: {} ({})".format(name, cv_results.mean(), cv_results.std()))


#scatter_matrix(data)
#plt.show()



fig = plt.figure()
fig.suptitle('CT475 - KNN Vs NB - 15315901')
ax = fig.add_subplot(111)
plt.boxplot(results)
ax.set_xticklabels(names)
plt.show()



#KNN
print('\nk Nearest Neighbours Prediction:')
knn = KNeighborsClassifier()
knn.fit(X_train, Y_train)
predictions = knn.predict(X_validation)
print('\nAccuracy Score:',accuracy_score(Y_validation, predictions))
print('\nConfusion Matrix:\n',confusion_matrix(Y_validation, predictions))
print('\nClassification Report:\n',classification_report(Y_validation, predictions))


#nb
print('\nNaive Bayes Prediction:')
nb = GaussianNB()
nb.fit(X_train, Y_train)
predictions = nb.predict(X_validation)
print('\nAccuracy Score:',accuracy_score(Y_validation, predictions))
print('\nConfusion Matrix:\n',confusion_matrix(Y_validation, predictions))
print('\nClassification Report:\n',classification_report(Y_validation, predictions))
