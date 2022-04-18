# List #

## Short description ##

This project was created as a homework from auxiliary courses of programming by [Ilya Dedinsky](https://github.com/ded32?tab=following).  
Main purpose of this project is working with such structure of data like a *List*.

## Features of data structure ##

List is a such data structure which has next features:

1. Addition in the list has asymptotics **o(1)** ([read about asymptotics here](http://cs.mipt.ru/wp/wp-content/uploads/2018/09/02-resource.pdf)).

2. Delete operation has asymptotics **o(1)**.

3. Finding an element in the list has asymptotics:

    3.1. **o(N)** in common case, where N - number of elements of the list.

    3.2. **o(1)** in case with linearizated list.

## How to build and launch ##

1. Clone this repository into your local directory with command:

    for SSH:

        git clone git@github.com:BileyHarryCopter/List.git

    for HTTP:

        git clone https://github.com/BileyHarryCopter/List.git

2. Go to the clonned repository with:

        cd List

    And launch compilation with make:

        make

3. After these steps you'll receive file **./start** which you need to launch the program:

        ./start

## Short command list ##

In this project I use incapsulation of *initialization* the structure due to hide fields of the list from user.

This procedure is needed for more safe working with the structure. Because of these principles user has folowing **command list**:

1. For creation a new list use **ListCtor (<name of a list>)**:

        <span style = "color:blue">List_t</span> *ListCtor (char * list_name);

2. For removal the list use **ListDtor (<list>)**:

        int ListDtor (List_t *list);

3. For receiving number of element in any order use functions:

    3.1. In logical order from physical number:

        int PhysToLog (List_t *list, int phys_pos);

    3.2. In physical order from logical number:

        int LogToPhys (List_t *list, int log_pos);

4. For inserting data in the list use **ListInsrt**:

    int ListInsrt (List_t *list, int mode, int insrt_ptr, data_t insrt_val);

    with several modes:

        Modes **NEXT** or **JUST** - insert after transmitted number of position.

        Mode **PREV** - insert before transmitted number of position.
