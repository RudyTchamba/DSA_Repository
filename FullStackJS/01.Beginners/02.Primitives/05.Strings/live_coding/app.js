let firstName = "Rudy";
let lastName = "Tchamba";
// we can also use: let latName = `Tchamba`;
//let fullName = firstName + lastName;
// console.log(fullName);

//1. CONCATENATION
// let fullName = firstName + " " + lastName
// let fullName = firstName.concat(lastName);

//2. APPEND
// firstName += " something else"

//3. LENGTH
// console.log(firstName.length);

//4. CASES
// console.log(firstName.toUpperCase());
// console.log(firstName.toLowerCase());

//5. SLICE
// console.log(fullName.slice(0, 3));

//6. SPLIT & JOIN
// console.log(fullName.split("")) -> this is going to have a results as ["R", "u", "d", "y"]
// console.log(fullName.split(" ")) -> his is going to have a results as ["Rudy"]
// console.log(fullName.split("").join("-"));

//7. INCLUDES
// console.log(fullName.includes("HuXn"));

//8. TRIM
// use to remove empty spaces
// console.log(fullName.trim());

// let desc = `this is some random 
//     Text
//     1
//     2
// `;

// console.log(desc);

// Another Way to do Concatenation

let fullName = `${firstName} ${lastName}`;