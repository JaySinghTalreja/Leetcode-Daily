//Alternative
SELECT Person.FirstName, Person.LastName, Address.City, Address.State from Person LEFT JOIN Address on Person.PersonId = Address.PersonId;


//Alternative
select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId;


//Alternative
SELECT `FirstName`, `LastName`, `City`, `State` FROM `Person` LEFT JOIN `Address` USING(`PersonId`)


//Alternative
SELECT FirstName, LastName, City, State FROM Address a
RIGHT JOIN Person p ON a.PersonId = p.PersonId