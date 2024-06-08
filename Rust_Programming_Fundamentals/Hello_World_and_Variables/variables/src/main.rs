mod exercise1;
mod exercise2;
mod exercise3;
mod exercise4;

fn main() 
{
    let name: &str = "Michael";
    println!("My name is {}", name);
    
    let apples: f32 = 10.333;
    println!("I have {} apples", apples);

    let apples: i32 = 10 + 5;
    println!("I have {} apples", apples);

    let answer: i32 = (6 / 2 + 4) * 3;
    println!("The answer is: {}", answer);

    let x: i32 = 5;
    let y: i32 = 10;
    let name: &str = "Michael";
    println!("My name is {}, and the answer is {}", name, x * y);

    let x: i32 = 5 + 3;
    let y: i32 = 2 - 1;
    let z: i32 = x * y;
    println!("The answer is {}", z);

    let my_var: u32 = 10;
    println!("my_var is {}", my_var);

    let mut name: String = String::from("Michael1"); // need to add "mut" to make the string mutable
    let age: u32 = 34;
    name.push_str(" Scott");
    println!("My name is {} and I am {} years old", name, age);

    //===================== exercises ==================================//
    exercise1::exercise1();
    exercise2::exercise2();
    exercise3::exercise3();
    exercise4::exercise4();

}
