#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <vector>

#include <Statme/Macros.h>

namespace HTTP
{
  namespace Response
  {
    struct TOCItem
    {
      std::string Title;
      std::string Link;
      std::string Descr;
    };

    typedef std::vector<TOCItem> TOCItemArray;
    typedef std::vector<std::string> StringArray;

    struct Formatter
    {
      TOCItemArray TOC;
      StringArray PRE;

    public:
      STATMELNK virtual ~Formatter();

      STATMELNK virtual std::string Run() = 0;
      STATMELNK virtual std::string GetMimeType() = 0;
      
      STATMELNK void AddTOCItem(
        const std::string& title
        , const std::string& link
        , const std::string& descr = std::string()
      );

      STATMELNK void AddLine(const std::stringstream& ss);
      STATMELNK void AddLine(const std::string& line);
    };

    typedef std::shared_ptr<Formatter> FormatterPtr;

    struct HtmlFormatter : public Formatter
    {
      std::string Run() override;
      std::string GetMimeType() override;
    };

    struct TextFormatter : public Formatter
    {
      std::string Run() override;
      std::string GetMimeType() override;
    };
  }
}