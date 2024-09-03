# Skyscraper

## How it works
When you call the Generate function it will first copy an already existing solution and then it will shuffle whole rows and collumns, when you shuffle a complete row or collumn it will still comply with the rules.

Example

1) 1 2 3 4
2) 2 3 4 1
3) 3 4 1 2
4) 4 1 2 3

when shuffle row 1 and row 2

1) 2 3 4 1
2) 1 2 3 4
3) 3 4 1 2
4) 4 1 2 3

as you can see the positions change but the overall shape doesnt, and you can also do this for the collumns and and for as many times as you want.

And then at the end it will generate the clues

## Preview
```
Enter the size of the grid (0 for quit): 4

    skyscrapers generated:

1 2 3 4
4 1 2 3
2 3 4 1
3 4 1 2

    constrains:

 2 3 2 1    
4       1    
1       2    
3       2    
2       2   
 2 1 2 3   
 
 
 
Enter the size of the grid (0 for quit): 5

    skyscrapers generated:

3 5 2 4 1
4 1 3 5 2
2 4 1 3 5
5 2 4 1 3
1 3 5 2 4

    constrains:

 3 1 4 2 3
2         3
2         2
3         1
1         3
3         2
 2 3 1 3 2
 ```








