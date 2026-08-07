pub fn reply(message: &str) -> &str {
    let msg = message.trim();
    let is_question = msg.ends_with("?");
    let is_capitalized = msg.chars().any(char::is_alphabetic) && 
        msg.chars().all(|ch| ch.is_uppercase() || !ch.is_alphabetic());
    match msg {
        "" => "Fine. Be that way!",
        _ if is_question && is_capitalized => "Calm down, I know what I'm doing!",
        _ if is_question => "Sure.",
        _ if is_capitalized => "Whoa, chill out!",
        _ => "Whatever."
    }
}
