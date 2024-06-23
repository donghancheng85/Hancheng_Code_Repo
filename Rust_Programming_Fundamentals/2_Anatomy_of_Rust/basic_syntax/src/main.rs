/**
 * In vscode, we can us control+shit+p and select "Format Document" to format the code
 * It uses the "rustfmt," which installed with Rust, to format the document for us.
 */
mod print_apple;
mod hello_world_with_comment;
mod format_code;

fn main() {
    let name: &str = "Michael";
    let x: () = println!("My name is {}", name); // unit type "()" is the same as "void" in C++
    let this_year: i32 = 2019;
    let birth_year: i32 = 1985;
    let age: i32 = this_year - birth_year;
    let y: () = println!("I turned {} in {}", age, this_year);
    assert_eq!(x, y);
    let _z: () = println!("Thanks for chatting with me!");

    println!("run print_apple function...");
    let num_apple: i32 = print_apple::print_apple();
    println!("I have {} apples", num_apple);

    println!("print hello world with comment...");
    hello_world_with_comment::print_hello_world();

    println!("run format_code() ...");
    format_code::format_code();
}
