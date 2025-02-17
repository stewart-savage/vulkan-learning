#pragma once

#include <expected>
#include <string>

/// This is where the magic happens
namespace App
{
    std::expected<void, std::string> run();
} // namespace App
