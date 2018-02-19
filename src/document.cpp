
#include <callista/app.hpp>
#include <callista/document/document.hpp>
#include <callista/document/designer_document.hpp>





void free_designer_document(DesignerDocument *document);

void free_document(Document *document) {
	if(!document) {
		console_error("Attempted to free a document that's already been freed!\n");
	}
	switch(document->kind) {
		case DOCTYPE_DESIGNER:
			free_designer_document((DesignerDocument *)document->data);
			break;
		default:
			console_error("Attempted to free unsupported document type '%d'\n", document->kind);
	}
	free(document->name);
	free(document);
}

void free_designer_document(DesignerDocument *document) {
	if(!document) {
		// TODO(zachary): Do we need to print a warning here?
		//                This may be called in document allocation cleanup code,
		//                in which a warning would be a red herring.
		return;
	}

	free(document);
}