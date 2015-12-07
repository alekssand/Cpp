public class File extends AbstractFile
{
	private String content;

	public File(String name, int pos, int parent, String content)
	{
		super(name, pos, parent);

		this.setFileContent(content);
	}

	public void setFileContent(String content)
	{
		this.content = content;
	}

	public String getFileContent()
	{
		return this.content;
	}
}