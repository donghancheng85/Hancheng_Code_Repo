/**
 * In vscode, we can us control+shit+p and select "Format Document" to format the code
 * It uses the "rustfmt," which installed with Rust, to format the document for us.
 */
fn main() {
    let name: &str = "Michael";
    let x: () = println!("My name is {}", name); // unit type "()" is the same as "void" in C++
    let this_year: i32 = 2019;
    let birth_year: i32 = 1985;
    let age: i32 = this_year - birth_year;
    let y: () = println!("I turned {} in {}", age, this_year);
    assert_eq!(x, y);
    let _z: () = println!("Thanks for chatting with me!");
}
