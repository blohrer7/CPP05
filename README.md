# CPP Module 05 – Repetition and Exceptions

## Overview

In **CPP05**, the goal is to deepen your understanding of **exceptions**, **error handling**, **class relationships**, and **object-oriented design** in C++.

This module builds on the previous C++ modules and introduces a small bureaucratic system involving **bureaucrats** and **forms**.

The main focus is on:

- using **try / catch**
- throwing and handling **exceptions**
- protecting classes from invalid states
- understanding **class interactions**
- working with **abstract base classes**

---

# Module Content

## Ex00 – Mommy, when I grow up, I want to be a bureaucrat!

In this exercise, you implement the **`Bureaucrat`** class.

A bureaucrat has:

- a **name**
- a **grade**

### Grade rules

The grade must always be between:

- **1** → highest rank
- **150** → lowest rank

If an invalid grade is given, an exception must be thrown:

- `GradeTooHighException`
- `GradeTooLowException`

### Important functions

- constructor
- copy constructor
- copy assignment operator
- destructor
- getters for name and grade
- functions to increase or decrease the grade:
  - `incrementGrade()`
  - `decrementGrade()`

### Learning goal

Here you learn:

- how to create **custom exceptions**
- how to protect an object’s **internal state**
- how to use `throw` and `catch`

---

## Ex01 – Form up, maggots!

Now the **`Form`** class is introduced.

A form has:

- a **name**
- a status showing whether it is **signed**
- a grade required to **sign** it
- a grade required to **execute** it

### Rules

The same grade limits still apply:

- minimum: `1`
- maximum: `150`

When a bureaucrat tries to sign a form, the program must check:

- is the bureaucrat’s grade high enough?
- is the form already signed?

### Important functions

- constructor
- getters
- `beSigned(const Bureaucrat& bureaucrat)`

In addition, `Bureaucrat` often gets a function such as:

- `signForm(Form& form)`

This allows a bureaucrat to try signing a form and display a useful message depending on the result.

### Learning goal

Here you learn:

- interaction between two classes
- clean error handling with exceptions
- protecting actions with proper condition checks

---

## Ex02 – No, you need form 28B, not 28C...

In this exercise, `Form` is replaced by an **abstract base class**:  
**`AForm`**

The difference is:

- `AForm` cannot be instantiated directly
- it contains at least one **pure virtual function**

You also create three concrete form classes:

### 1. `ShrubberyCreationForm`

- creates a file
- writes ASCII trees into it

### 2. `RobotomyRequestForm`

- performs a robotomy procedure
- has a **50% success rate**
- prints the result

### 3. `PresidentialPardonForm`

- pardons a target
- prints an appropriate message

### Important new concepts

- inheritance
- abstract classes
- polymorphism
- virtual functions

### Typical function

Each form has an `execute()` function.

Before execution, the program must check:

- is the form signed?
- does the bureaucrat have a high enough grade?

If not, an exception must be thrown.

### Learning goal

Here you understand:

- why abstract classes are useful
- how different classes can share the same interface
- how to place common logic in a base class

---

## Ex03 – At least this beats coffee-making

In the last exercise, the **`Intern`** class is introduced.

The intern can create forms without the caller directly instantiating the concrete class.

### Role of `Intern`

A function such as:

```cpp
AForm* makeForm(std::string formName, std::string target);