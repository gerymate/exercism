
/// various log levels
#[derive(Clone, PartialEq, Eq, Debug)]
pub enum LogLevel {
    Info,
    Warning,
    Error,
}
/// primary function for emitting logs
pub fn log(level: LogLevel, message: &str) -> String {
  let header = match level {
    LogLevel::Info => "[INFO]",
    LogLevel::Error => "[ERROR]",
    LogLevel::Warning => "[WARNING]",
  };
  header.to_string() + ": " + message
}
pub fn info(message: &str) -> String {
  log(LogLevel::Info, message)
}
pub fn warn(message: &str) -> String {
  log(LogLevel::Warning, message)
}
pub fn error(message: &str) -> String {
  log(LogLevel::Error, message)
}
