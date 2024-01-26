#pragma  once

#include "pub.hpp"
#include <rapidjson/prettywriter.h>
namespace json_dto
{


	template <typename Dto> std::string to_json_p(const Dto& dto)
	{
		rapidjson::Document output_doc;
		json_output_t       jout{ output_doc, output_doc.GetAllocator() };

		jout << dto;

		rapidjson::StringBuffer                    buffer;
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
		output_doc.Accept(writer);

		return buffer.GetString();
	}

	template< typename Type >
	void to_stream_p(std::ostream& to, const Type& type)
	{
		rapidjson::Document output_doc;
		json_dto::json_output_t jout{
			output_doc, output_doc.GetAllocator() };

		jout << type;

		rapidjson::OStreamWrapper wrapper{ to };
		rapidjson::PrettyWriter< rapidjson::OStreamWrapper > writer{ wrapper };
		output_doc.Accept(writer);
	}
}