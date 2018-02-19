#pragma once

#include <callista/types.hpp>

enum DocumentType {
	DOCTYPE_DESIGNER,
	DOCTYPE_PHOTO,
	DOCTYPE_ANIMATE,
	DOCTYPE_VIDEO
};

// Documents are the base type for all open files,
// like each window with an image open in an image editor.
struct Document {
	DocumentType kind;
	int version;
	bool is_modified;
	char *name;
	void *data;
};

void free_document(Document *document);